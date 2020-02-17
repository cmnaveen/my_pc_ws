#ffmpeg -f x11grab -r 25 -s 720x480 -i :0.0+0,0 -f alsa -ac 2 -i pulse output.mp4

ffmpeg -video_size 720x480 -framerate 25 -f x11grab -i :0.0+100,200 output.mp4


