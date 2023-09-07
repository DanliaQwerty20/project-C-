using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShopTortApp.Storage.Entities
{
    public class Order
    {
        [Key]
        public int Id { get; set; }


        public int price { get; set; }

        public int counterCake { get; set; }

        public int status { get; set; }

        public int weight { get; set; }

        public int height { get; set; }

        public string place { get; set; }
        

        public int CakeId { get; set; }

        
        public int ClientId { get; set; }
        
        public int FillingId { get; set; }
        
        public virtual Cake Cake { get; set; }

        public virtual Filling Filling { get; set;}

        public virtual Client Client { get; set; }
    }
}
