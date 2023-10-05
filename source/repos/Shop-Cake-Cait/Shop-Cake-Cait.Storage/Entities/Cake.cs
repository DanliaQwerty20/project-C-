using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shop_Cake_Cait.Storage.Entities
{
    public class Cake
    {
        [Key]

        public int Id { get; set; } 

        public string Name { get; set; }    

        public string Description { get; set; }

        public double Weight { get; set; }
        public int Price { get; set; }
        public int ReviewsId { get; set; }
        public int Reviews { get; set; }

        public int CatalogId { get; set; }
        public int Catalog { get; set; }


    }
}
