#
# Be sure to run `pod lib lint LCManager.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LCManager'
  s.version          = '1.0.0'
  s.summary          = '初次尝试上传项目到cocoapods.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: 这是一个悲伤的故事,到底可以吗???,不能比sunmmary短,再说两句吧,希望可以成功啊.
                       DESC

  s.homepage         = 'https://github.com/loversunny/LCManager'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'JLC' => 'HH330897537@163.com' }
  s.source           = { :git => 'https://github.com/loversunny/LCManager.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'LCManager/Classes/**/*'
  
  # s.resource_bundles = {
  #   'LCManager' => ['LCManager/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
