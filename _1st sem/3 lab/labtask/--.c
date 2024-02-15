// размеры "экрана"
// по оси абсцисс    
#define scene_length 150
// по оси ординат 
#define scene_width 40    
  char scene[scene_length][scene_width*2]; // тут будем график рисовать. по оси ординат делаем в 2 раза больше (под отрицательные значения)

  for(int x=0;x<scene_length;x++){ // чистим массив
      for(int y=0;y<scene_width*2;y++)
          scene[x][y]='.';
      scene[x][scene_width]='-'; // это будет абсцисса
  }

  // тут будем обсчитывать функцию и рисовать график
  for(int x=0;x<scene_length;x++){
      double y = 2*x; // моя функция      
      if(abs(y)<scene_width) // проверяем чтобы значение за пределы "экрана" не выходило
          scene[x][(int)round(y-scene_width)]='*'; // ставим точку

  }
  // выводим на экран
  for(int y=scene_width*2-1;y>=0;y--){
      printf ("%03d ", y-scene_width);
      for(int x=0;x<scene_length;x++){
          printf("%c",scene[x][y]);
      }
      printf("\n");
  }

    return 0;