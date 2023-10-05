using Microsoft.EntityFrameworkCore;
using Microsoft.OpenApi.Models;
using ShopTortApp.Storage;
using System.Net;
using System.Text;

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

        // Создаем объект HttpListener
        HttpListener listener = new HttpListener();
        // Указываем адрес, на котором будет слушать сервер
        listener.Prefixes.Add("http://25.27.145.30:8080/");

        try
        {
            // Запускаем сервер
            listener.Start();
            Console.WriteLine("Сервер запущен. Ожидание запросов...");

            while (true)
            {
                // Принимаем входящий запрос
                HttpListenerContext context = listener.GetContext();

                // Получаем объект запроса и ответа
                HttpListenerRequest request = context.Request;
                HttpListenerResponse response = context.Response;

                using (StreamReader reader = new StreamReader(request.InputStream))
                {
                    string requestData = reader.ReadToEnd();
                    Console.WriteLine($"Получен запрос: {requestData}");
                }

                string responseString = "Првет, мир!";
                byte[] responseBytes = Encoding.UTF8.GetBytes(responseString);
                response.ContentType = "text/plain";
                response.ContentLength64 = responseBytes.Length;

                using (Stream output = response.OutputStream)
                {
                    output.Write(responseBytes, 0, responseBytes.Length);
                }

                Console.WriteLine("Ответ отправлен.");
            }
            }
        catch (HttpListenerException e)
        {
            Console.WriteLine($"Ошибка: {e.Message}");
        }
        finally
        {
            // Останавливаем сервер
            listener.Close();
            listener.Stop();
        }

        app.Run();
    }
}