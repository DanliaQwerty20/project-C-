using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace Confectionery6PiecesTest1.Controllers
{
    [Route("api/users")]
    [ApiController]
    public class UserController : ControllerBase
    {
        [HttpGet]
        public IActionResult GetUsers()
        {
            var users = new[]
            {
                new { Name = "Oleg"},
                new { Name = "Ivan"}
            };
            return Ok(users);
        }
    }
}
