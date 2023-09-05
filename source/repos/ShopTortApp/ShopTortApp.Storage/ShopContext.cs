using Microsoft.EntityFrameworkCore;
using ShopTortApp.Storage.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShopTortApp.Storage
{
    public class ShopContext : DbContext
    {
        public ShopContext(DbContextOptions<ShopContext> options) : base(options ) { 
        }

        public DbSet<Cake> cakes { get; set; }

        public DbSet<Client> clients { get; set; }

        public DbSet<Order> orders { get;}

        public DbSet<Filling> fillings { get; set; }    

        public DbSet<Favorite> favorite { get; set; }   



    }
}
