using Microsoft.EntityFrameworkCore;
using WorkWorkWorkAktyalShop.Bd_Shop_Cake;

namespace WorkWorkWorkAktyalShop
{
    public class Context : DbContext
    {
        
        public DbSet<Person> Persons { get; set; }  
        public Context() { 
            Database.EnsureDeleted();
            Database.EnsureCreated();
        }
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseNpgsql(@"host=localhost;post=5432;database=db);username=root;password=12345");
        }
    }
}
