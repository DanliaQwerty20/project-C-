using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShopTortApp.Storage.Entities
{
    public class Favorite
    {
        [Key]
        public int Id { get; set; }

        public string nameCake { get; set; }


        public string description { get; set; }

        public int counterCake { get; set; }

        public virtual ICollection<Cake> Cakes{ get; set; }
    }
}
