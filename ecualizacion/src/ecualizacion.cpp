#include <iostream>
#include <opencv2/core.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"

int main(int argc, char** argv) {
  cv::CommandLineParser parser(argc, argv, "{@input | ../felpuchina.jpg | input image}");
  cv::Mat src = cv::imread(cv::samples::findFile(parser.get<cv::String>("@input")), cv::IMREAD_COLOR);
  if (src.empty()) {
    std::cout << "Could not open or find the image!\n" << std::endl;
    std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
    return -1;
  }
  cv::Mat dst;
  std::vector<cv::Mat> channels;

  cv::split(src, channels);
  for(const cv::Mat &channel : channels) {
    cv::equalizeHist(channel, channel);
  }
  cv::merge(channels, dst);

  cv::imshow("Source image", src);
  cv::imshow("Equalized Image", dst);
  cv::waitKey();
  return 0;
}
