using Microsoft.AspNetCore.Http.Extensions;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using ShopTortApp.Storage;
using ShopTortApp.Storage.Entities;
using System.Text;

namespace ShopTortApp.Logic.controller
{

    [ApiController]
    [Route("fillings")]
    public class FillingController : ControllerBase
    {
        private readonly ShopContext _dbContext;
        public FillingController(ShopContext dbContext)
        {
            _dbContext = dbContext;
        }
        
        [HttpGet("{id}")]
        public async Task<ActionResult<Filling>> GetFilling(int id)
        {
            var filling = await _dbContext.fillings.FindAsync(id);

            if (filling == null)
            {
                return NotFound();
            }

            return Ok(filling);
        }

        [HttpGet]
        public IActionResult GetAll()
        {
            var users = _dbContext.fillings.ToList();
            return Ok(users);
        }
        
        [HttpPost]
        public async Task<ActionResult<Filling>> PostFilling(Filling filling)
        {
            _dbContext.fillings.Add(filling);
            await _dbContext.SaveChangesAsync();

            return CreatedAtAction(nameof(GetFilling), new { id = filling.Id }, filling);
        }
        
        [HttpPut("{id}")]
        public async Task<IActionResult> PutFilling(int id, Filling filling)
        {
            if (id != filling.Id)
            {
                return BadRequest();
            }

            _dbContext.Entry(filling).State = EntityState.Modified;

            try
            {
                await _dbContext.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!FillingExists(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return NoContent();
        }
        [HttpGet]
        [Route("test")]
        public async Task<IActionResult> test()
        {
            
            return Ok("hello world"); }

        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteFilling(int id)
        {
            var filling = await _dbContext.fillings.FindAsync(id);

            if (filling == null)
            {
                return NotFound();
            }

            _dbContext.fillings.Remove(filling);
            await _dbContext.SaveChangesAsync();

            return NoContent();
        }

        private bool FillingExists(int id)
        {
            return _dbContext.fillings.Any(c => c.Id == id);
        }
    }
}
