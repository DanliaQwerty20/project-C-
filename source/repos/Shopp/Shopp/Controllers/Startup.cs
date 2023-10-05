using Microsoft.AspNetCore.SpaServices;
using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.AspNetCore.SpaServices.Prerendering;
using Microsoft.AspNetCore.SpaServices.Webpack;

namespace ProjectNamespace.Startup
{
    public class StartupClass
    {
        public void ConfigureServices(IServiceCollection services)
        {
            // ...

            // Добавляем настройки SPA with React
            services.AddSpaStaticFiles(configuration =>
            {
                configuration.RootPath = "ClientApp/build";
            });

            // ...
        }

        // ...

        public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
        {
            // ...

            app.UseStaticFiles();
            app.UseRouting();
            app.UseAuthorization();

            // ...

            object value = app.UseSpa(spa =>
            {
                spa.Options.SourcePath = "ClientApp";
                if (env.IsDevelopment())
                {
                    spa.UseReactDevelopmentServer(npmScript: "start");
                }
            });
        }
    }
}