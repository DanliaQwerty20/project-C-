using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shop_Cake_Cait.Storage.Entities
{
    public class CakeOrders
    {
        [Key]
        public int Id { get; set; }

        public int OrderId { get; set; }

        public int Quantity { get; set; }

        
    }
}
