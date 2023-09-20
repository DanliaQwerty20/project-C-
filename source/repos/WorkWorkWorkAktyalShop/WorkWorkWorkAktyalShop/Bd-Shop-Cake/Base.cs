using Microsoft.EntityFrameworkCore.Metadata.Internal;
using Microsoft.EntityFrameworkCore.Migrations;
namespace WorkWorkWorkAktyalShop.Bd_Shop_Cake
{
    public class Base : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            //1.миграция для тортов(самая основная)
            migrationBuilder.CreateTable(
                name: "Cakes",
                columns: table => new
                {
                    Id = table.Column<int>(type: "INTEGER", nullable: false)
                    .Annotation("Sqlite:Autoincrement", true),
                    Name = table.Column<string>(type: "TEXT", nullable: false),
                    Description = table.Column<string>(type: "TEXT", nullable: true),
                    Weight = table.Column<double>(type: "REAL", nullable: false),
                    Price = table.Column<int>(type: "INTEGER", nullable: false),
                    ReviewsId = table.Column<int>(type: "INTEGER", nullable: true),
                    CatalogId = table.Column<int>(type: "INTEGER", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Cakes", x => x.Id);
                });
            //2.миграция связи между Тортом и заказом
            migrationBuilder.CreateTable(
                name: "CakeOrders",
                columns: table => new
                {
                    CakeId = table.Column<int>(type: "INTEGER", nullable: false),
                    OrderId = table.Column<int>(type: "INTEGER", nullable: false),
                    Quantity = table.Column<int>(type: "INTEGER", nullable: false),
                    Cost = table.Column<int>(type: "INTEGER", nullable: false),
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_CakeOrders", x => new { x.CakeId, x.OrderId });
                    table.ForeignKey(
                    name: "FK_CakeOrders_Cakes_CakeId",
                    column: x => x.CakeId,
                    principalTable: "Cakes",
                    principalColumn: "Id",
                    onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                    name: "FK_CakeOrders_Orders_OrderId",
                    column: x => x.OrderId,
                    principalTable: "Orders",
                    principalColumn: "Order_number",
                    onDelete: ReferentialAction.Cascade);
                });
            //3.миграция Начинка
            migrationBuilder.CreateTable(
                name: "Fillings",
                columns: table => new
                {
                    Id = table.Column<int>(type: "INTEGER", nullable: false)
                    .Annotation("Sqlite:Autoincrement", true),
                    Name = table.Column<string>(type: "TEXT", nullable: false),
                    Description = table.Column<string>(type: "TEXT", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Fillings", x => x.Id);
                });


            //4.миграция для заказов
            migrationBuilder.CreateTable(
                name: "Orders",
                columns: table => new
                {
                    Order_number = table.Column<int>(type: "INTEGER", nullable: false)
                    .Annotation("Sqlite:Autoincrement", true),
                    CustomerId = table.Column<int>(type: "INTEGER", nullable: false),
                    Order_date = table.Column<string>(type: "TEXT", nullable: false),
                    Quantity = table.Column<int>(type: "INTEGER", nullable: false),
                    Cost = table.Column<int>(type: "INTEGER", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Orders", x => x.Order_number);
                    table.ForeignKey(
                    name: "FK_Orders_Customers_CustomerId",
                    column: x => x.CustomerId,
                    principalTable: "Customers",
                    principalColumn: "Id",
                    onDelete: ReferentialAction.Cascade);
                });
            //5.миграция для хранения информации о клиентах
            migrationBuilder.CreateTable(
                name: "Customers",
                columns: table => new
                {
                    Id = table.Column<int>(type: "INTEGER", nullable: false)
                    .Annotation("Sqlite:Autoincrement", true),
                    Name = table.Column<string>(type: "TEXT", nullable: false),
                    Address = table.Column<string>(type: "TEXT", nullable: false),
                    Phone_number = table.Column<string>(type: "TEXT", nullable: false),
                    Email = table.Column<string>(type: "TEXT", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Customers", x => x.Id);
                });

            //6.Миграция для Категории
            migrationBuilder.CreateTable(
                name: "Categories",
                columns: table => new
                {
                    Id = table.Column<int>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    Name = table.Column<string>(type: "TEXT", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Categories", x => x.Id);
                });
            //7.маграция связи между Категория и Торт
            migrationBuilder.CreateTable(
                name: "CakeCategories",
                columns: table => new
                {
                    CakeId = table.Column<int>(type: "INTEGER", nullable: false),
                    CategoryId = table.Column<int>(type: "INTEGER", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_CakeCategories", x => new { x.CakeId, x.CategoryId });
                    table.ForeignKey(
                    name: "FK_CakeCategories_Cakes_CakeId",
                    column: x => x.CakeId,
                    principalTable: "Cakes",
                    principalColumn: "Id",
                    onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                    name: "FK_CakeCategories_Categories_CategoryId",
                    column: x => x.CategoryId,
                    principalTable: "Categories",
                    principalColumn: "Id",
                    onDelete: ReferentialAction.Cascade);
                });
            //8. маграция для отзывов
            migrationBuilder.CreateTable(
                name: "Reviews",
                columns: table => new
                {
                    Id = table.Column<int>(type: "INTEGER", nullable: false)
                    .Annotation("Sqlite:Autoincrement", true),
                    CakeId = table.Column<int>(type: "INTEGER", nullable: false),
                    Author = table.Column<string>(type: "TEXT", nullable: false),
                    Text = table.Column<string>(type: "TEXT", nullable: false),
                    Rating = table.Column<int>(type: "INTEGER", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Reviews", x => x.Id);
                    table.ForeignKey(
                    name: "FK_Reviews_Cakes_CakeId",
                    column: x => x.CakeId,
                    principalTable: "Cakes",
                    principalColumn: "Id",
                    onDelete: ReferentialAction.Cascade);
                });
            migrationBuilder.CreateIndex(
                name: "IX_",
                table: "",
                column: " "
                );
        }
        protected override void Down(MigrationBuilder migrationBuilder)
        {

            migrationBuilder.DropTable(
                name: "Cakes");

            migrationBuilder.DropTable(
                name: "CakeOrders");

            migrationBuilder.DropTable(
                name: "Fillings");

            migrationBuilder.DropTable(
                name: "Orders");

            migrationBuilder.DropTable(
                name: "Customers");

            migrationBuilder.DropTable(
                name: "Categories");

            migrationBuilder.DropTable(
                name: "CakeCategories");

            migrationBuilder.DropTable(
                name: "Reviews");
        }

    }
}
