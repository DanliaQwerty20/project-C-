using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShopTortApp.Storage.Entities
{
    public class Cake
    {
        [Key]
        public int Id { get; set; }

        public string name { get; set; }
        public string description { get; set; }

        public int price { get; set; }

        public int filePath { get; set; }

        public int FavorityId { get; set; }

        public virtual Favorite Favorite { get; set; }


        public virtual ICollection<Order> orders { get; set; }
    }
}
