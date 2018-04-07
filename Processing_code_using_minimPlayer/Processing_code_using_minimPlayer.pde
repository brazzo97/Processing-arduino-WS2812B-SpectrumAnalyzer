import processing.serial.*;
import ddf.minim.analysis.*;
import ddf.minim.*;

Minim       minim;
AudioPlayer cd;
FFT         fft;
Serial arduino;
 
 
 int freq_width = 1000;
 int[] Line = new int[26];
 
 
 int[] freq_array = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float[] freq_height = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

 
 
 
 
void setup()
{
  size(512, 200, P3D);
  
  minim = new Minim(this);
  arduino = new Serial(this, "COM11", 125000);
  // specify that we want the audio buffers of the AudioPlayer
  // to be 1024 samples long because our FFT needs to have 
  // a power-of-two buffer size and this is a good size.
  cd = minim.loadFile("Jingle.mp3", 4096);
  
  // loop the file indefinitely
  cd.loop();
  
  // create an FFT object that has a time-domain buffer 
  // the same size as jingle's sample buffer
  // note that this needs to be a power of two 
  // and that it means the size of the spectrum will be half as large.
  fft = new FFT( cd.bufferSize(), cd.sampleRate() );
  
}

void draw()
{
  background(0);
  stroke(255);
  
  for(int i = 0; i < cd.bufferSize() - 1; i++)
  {
    line(i, 50  + cd.left.get(i)*50,  i+1, 50  + cd.left.get(i+1)*50);
    line(i, 150 + cd.right.get(i)*50, i+1, 150 + cd.right.get(i+1)*50);
  }
  
  stroke( 255, 0, 0 );
  float position = map( cd.position(), 0, cd.length(), 0, width );
  line( position, 0, position, height );
  
  text("Click anywhere to jump to a position in the song.", 10, 20);










for(int k=0; k<64; k++){
freq_array[k] = 0;
}

  // perform a forward FFT on the samples in input buffer
  fft.forward( cd.mix );
  
  
  freq_height[0] = fft.calcAvg((float) 0, (float) 31);
  freq_height[1] = fft.calcAvg((float) 32, (float) 62);
  freq_height[2] = fft.calcAvg((float) 63, (float) 125);
  freq_height[3] = fft.calcAvg((float) 126, (float) 250);
  freq_height[4] = fft.calcAvg((float) 251, (float) 500);
  freq_height[5] = fft.calcAvg((float) 501, (float) 750);
  freq_height[6] = fft.calcAvg((float) 751, (float) 1000);
  freq_height[7] = fft.calcAvg((float) 1001, (float) 1500);
  freq_height[8] = fft.calcAvg((float) 1501, (float) 2000);
  freq_height[9] = fft.calcAvg((float) 2001, (float) 4000);
  freq_height[10] = fft.calcAvg((float) 4001, (float) 8000);
  freq_height[11] = fft.calcAvg((float) 8001, (float) 16001);
  


  float x = 8;
  float y = 3;
 for(int j=0; j<12; j++){    
    freq_height[j] = freq_height[j]*(log(x)/y);
    x = x + (x); 
  }
  

   

// Amplitude Ranges  if else tree
    for(int j=0; j<12; j++){    
    if (freq_height[j] < 2000 && freq_height[j] > 180){freq_array[j] = 12;}
    else{ if (freq_height[j] <= 180 && freq_height[j] > 130){freq_array[j] = 11;}
    else{ if (freq_height[j] <= 130 && freq_height[j] > 100){freq_array[j] = 10;}
    else{ if (freq_height[j] <= 100 && freq_height[j] > 75){freq_array[j] = 9;}
    else{ if (freq_height[j] <= 75 && freq_height[j] > 60){freq_array[j] = 8;}
    else{ if (freq_height[j] <= 60 && freq_height[j] > 45){freq_array[j] = 7;}
    else{ if (freq_height[j] <= 45 && freq_height[j] > 32){freq_array[j] = 6;}
    else{ if (freq_height[j] <= 32 && freq_height[j] > 25){freq_array[j] = 5;}
    else{ if (freq_height[j] <= 25 && freq_height[j] > 18){freq_array[j] = 4;}
    else{ if (freq_height[j] <= 18 && freq_height[j] > 12){freq_array[j] = 3;}
    else{ if (freq_height[j] <= 12 && freq_height[j] > 6){freq_array[j] = 2;}
    else{ if (freq_height[j] <= 6 && freq_height[j] > 2){freq_array[j] = 1;}
    else{ if (freq_height[j] <= 2 && freq_height[j] > 0){freq_array[j] = 0;}
  }}}}}}}}}}}}}
for(int z=0 ; z<12;z++)
{
Line[z] = freq_array[z];
print(Line[z]);
print(" ");

}
println();
 arduino.write("a" + Line[0]);
 arduino.write("b" + Line[1]);
 arduino.write("c" + Line[2]);  
 arduino.write("d" + Line[3]);
 arduino.write("e" + Line[4]);
 arduino.write("f" + Line[5]);
 arduino.write("g" + Line[6]);
 arduino.write("h" + Line[7]);
 arduino.write("i" + Line[8]);
 arduino.write("y" + Line[9]);
 arduino.write("k" + Line[10]);
 arduino.write("l" + Line[11]);
 arduino.write("m" + Line[12]);
 }
  
  
  void mousePressed()
{
  // choose a position to cue to based on where the user clicked.
  // the length() method returns the length of recording in milliseconds.
  int position = int( map( mouseX, 0, width, 0, cd.length() ) );
  cd.cue( position );
}
