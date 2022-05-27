
#include <iostream>
#include <string>

#include "cimg/CImg.h"

using namespace cimg_library;


static constexpr int SCREEN_WIDTH = 560;
static constexpr int SCREEN_HEIGHT = 384;

int main(int argc, char* argv[])
{
  constexpr unsigned char red[] = { 255,0,0 }
  , green[] = { 0,255,0 }
  , blue[] = { 0,0,255 }
  , black[] = { 0, 0, 0 };

  const std::string str{ "Hello World!" };

  CImg<unsigned char> img(SCREEN_WIDTH, SCREEN_HEIGHT, 1, 3, 0);
  CImgDisplay window(img, str.c_str());

  constexpr int fontSize = 23;
  constexpr int opacity = 1;
  img.draw_text(0, 0, str.c_str(), red, blue, opacity, fontSize)
     .display(window);

  while (!window.is_closed())
  {
    window.wait(); // wait for an event
  }

  return 0;
}