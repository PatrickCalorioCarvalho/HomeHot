using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace HomeHot.Models
{
    public class Sensor
    {
        [Key]
        public int IDSensor { get; set; }

        public string Nome { get; set; }

        public float Umidade { get; set; }

        public float Temperatura { get; set; }

        public DateTime Data { get; set; }

    }
}
