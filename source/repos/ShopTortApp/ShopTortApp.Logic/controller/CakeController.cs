using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using ShopTortApp.Storage.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using ShopTortApp;

namespace ShopTortApp.Storage.controller
{
    [Route("[controller]")]
    [ApiController]
    public class CakeController : ControllerBase
    {
        private readonly ShopContext _dbContext;

        public CakeController(ShopContext dbContext)
        {
            _dbContext = dbContext;
        }

        [HttpGet("cakes/{id}")]
        public async Task<ActionResult<Cake>> GetCake(int id)
        {
            var cake =await _dbContext.cakes.FindAsync(id);
           

            if (cake == null)
            {
                return NotFound();
            }

            return Ok(cake);
        }


        [HttpPost("cakes")]
        public async Task<ActionResult<Cake>> PostCake(Cake cake)
        {
            _dbContext.cakes.Add(cake);
            await _dbContext.SaveChangesAsync();

            return CreatedAtAction(nameof(GetCake), new { id = cake.Id }, cake);
        }

        [HttpPut("cakes/{id}")]
        public async Task<IActionResult> PutCake(int id, Cake cake)
        {
            if (id != cake.Id)
            {
                return BadRequest();
            }

            _dbContext.Entry(cake).State = EntityState.Modified;

            try
            {
                await _dbContext.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!CakeExists(id))
                {
                    return NotFound();
                }

                throw;
            }

            return NoContent();
        }
        [HttpGet("cakes")]
        public IActionResult GetAll()
        {
            var users = _dbContext.cakes.ToList();
            return Ok(users);
        }

        [HttpDelete("cakes/{id}")]
        public async Task<IActionResult> DeleteCake(int id)
        {

            var cake = await _dbContext.cakes.FindAsync(id);

            if (cake == null)
            {
                return NotFound();
            }

            _dbContext.cakes.Remove(cake);
            await _dbContext.SaveChangesAsync();

            return NoContent();
        }

        private bool CakeExists(int id)
        {
            return _dbContext.cakes.Any(c => c.Id == id);
        }
    }
}
