using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShopTortApp.Logic.controller
{
    [Route("api/photos")]
    [ApiController]
    public class PhotoCakeController
    {

        private readonly string _photosFolderPath = "static/filling";

        [HttpGet("{photoName}")]
        public IActionResult GetPhoto(string photoName)
        {
            var imagePath = Path.Combine(_photosFolderPath, photoName);

            if (!System.IO.File.Exists(imagePath))
            {
                return NotFound();
            }

            var imageFileStream = new FileStream(imagePath, FileMode.Open, FileAccess.Read);

            return File(imageFileStream, "image/png"); // Предполагается, что все фотографии имеют формат PNG
        }
    }
}
