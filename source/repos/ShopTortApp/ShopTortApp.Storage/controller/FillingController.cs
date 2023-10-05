using Microsoft.AspNetCore.Http.Extensions;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;
using NLog;
using ShopTortApp.Storage;
using ShopTortApp.Storage.Entities;
using System.Reflection;
using System.Text;



namespace ShopTortApp.Logic.controller
{

    [ApiController]
    [Route("api/[controller]")]
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
            var commonLogger = LogManager.GetLogger("Common");
            if (filling == null)
            {
                return NotFound();
            }
            commonLogger.Debug("Executing GetFilling method");
           
            return Ok(filling);
        }

        [HttpGet]
        public IActionResult GetAll()
        {
            Console.WriteLine("Executing GetAll method");
            var commonLogger = LogManager.GetLogger("Common");
            var fillings = _dbContext.fillings.ToList();
            commonLogger.Debug("Executing PostFilling method");
            return Ok(fillings);
        }

        [HttpPost]
        public async Task<ActionResult<Filling>> PostFilling(Filling filling)
        {
            var commonLogger = LogManager.GetLogger("Common");
            Console.WriteLine("Executing PostFilling method");
            commonLogger.Debug("Executing PostFilling method");
            _dbContext.fillings.Add(filling);
            await _dbContext.SaveChangesAsync();

            return CreatedAtAction(nameof(GetFilling), new { id = filling.Id }, filling);
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> PutFilling(int id, Filling filling)
        {
            Console.WriteLine("Executing PutFilling method");
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
            Console.WriteLine("Executing test method");
            return Ok("hello world");
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteFilling(int id)
        {
            Console.WriteLine("Executing DeleteFilling method");
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
