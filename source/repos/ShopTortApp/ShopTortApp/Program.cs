using Microsoft.EntityFrameworkCore;
using Microsoft.OpenApi.Models;
using ShopTortApp.Storage;

public class Program
{
    private static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);

        // Add services to the container.
        builder.Services.AddControllersWithViews();

       builder.Services.AddControllersWithViews();

        // Add CORS
        builder.Services.AddCors(options =>
        {
            options.AddDefaultPolicy(builder =>
            {
                builder.AllowAnyOrigin()
                       .AllowAnyHeader()
                       .AllowAnyMethod();
            });
        });


        var connectionString = builder.Configuration.GetConnectionString("DbConnection");
        builder.Services.AddDbContext<ShopContext>(param => param.UseSqlServer(connectionString));

        // Add Swagger
        builder.Services.AddSwaggerGen(c =>
        {
            c.SwaggerDoc("v1", new OpenApiInfo { Title = "Task Management API", Version = "v1" });
        });

        var app = builder.Build();
        app.UseRouting();

        // Configure Swagger UI and JSON endpoints
        app.UseSwagger();
        app.UseSwaggerUI(c =>
        {
            c.SwaggerEndpoint("/swagger/v1/swagger.json", "Task Management API");
        });

        app.UseEndpoints(endpoints =>
        {
            endpoints.MapControllers();
        });



        // Configure the HTTP request pipeline.
        if (!app.Environment.IsDevelopment())
        {
            app.UseExceptionHandler("/Home/Error");
            // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
            app.UseHsts();
        }


        app.UseHttpsRedirection();
        app.UseStaticFiles();
        Console.WriteLine("Program 1:");
        app.UseCors();
        app.UseRouting();

        app.UseAuthorization();

        app.MapControllerRoute(
            name: "default",
            pattern: "{controller=Home}/{action=Index}/{id?}");

        app.Run();
    }
}