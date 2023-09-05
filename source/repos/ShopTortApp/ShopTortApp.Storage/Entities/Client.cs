using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShopTortApp.Storage.Entities
{
    public class Client
    {
        [Key]
        public int Id { get; set; }

        public string login { get; set; }

        public int password { get; set; }

        public string email { get; set; }

        public string contacts { get; set; }

        public virtual ICollection<Order> orders { get; set; }
    }
}
