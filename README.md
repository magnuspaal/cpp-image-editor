# cpp-image-editor
Käivitamiseks on vaja ImageMagickut(). Windows: [ImageMagick](https://imagemagick.org/script/download.php#windows) (valida tuleb "install legacy utilities") ja [GraphicsMagick](http://www.graphicsmagick.org/download.html). Mac OS: brew install imagemagick (vaja läheb [homebrew'd](https://brew.sh/)). Ubuntu: sudo apt install imagemagick (pole testinud).

See järel saab jooksutada *make* ja kausta tekib *main* programm. Sellele peab argumendiks andma pildi nime ja vähemalt ühe funktsiooni, mis sooritatakse etteantud järjekorras. Nendeks funktsioonideks on:

-i: inverteerib värvid.

-f (v|h): peegeldab pilti vertikaalselt või horisontaalselt.

-o (l|r): pöörab pildi vasakule või paremale.

-x <width> <height>: muudab pildi laiust ja kõrgust.

-e <factor>: muudab pilti tumedamaks (factor < 1) või heledamaks (factor > 1). 
