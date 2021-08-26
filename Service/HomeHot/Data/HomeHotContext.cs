using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;

namespace HomeHot.Models
{
    public class HomeHotContext : DbContext
    {
        public HomeHotContext (DbContextOptions<HomeHotContext> options)
            : base(options)
        {
        }

        public DbSet<HomeHot.Models.Sensor> Sensor { get; set; }
    }
}
