using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace ShopTortApp.Storage.Migrations
{
    /// <inheritdoc />
    public partial class newFixatribyt : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<string>(
                name: "fileImg",
                table: "fillings",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<string>(
                name: "fileImg",
                table: "cakes",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "fileImg",
                table: "fillings");

            migrationBuilder.DropColumn(
                name: "fileImg",
                table: "cakes");
        }
    }
}
