using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShopTortApp.Storage.Entities
{
    public class Filling
    {
        [Key]
        public int Id { get; set; }

        public string Name { get; set; }

        public string Description { get; set; }

        public int price { get; set; }

        public string filePath { get; set; }

        public string fileImg {get; set; }

        public virtual ICollection<Order> orders { get; set; }
    }
}
