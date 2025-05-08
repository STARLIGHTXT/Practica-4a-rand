/* calc.x - Definición del servicio RPC de calculadora */
program CALC_PROG {
  version CALC_VERS {
    int suma(int, int) = 1;
    int resta(int, int) = 2;
    int multiplica(int, int) = 3;
    int divide(int, int) = 4;
  } = 1;
} = 0x32222222;