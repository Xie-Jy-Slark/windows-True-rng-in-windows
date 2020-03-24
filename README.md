# windows-True-rng-in-windows
windows下的获得真随机数的类，随机数满足均匀分布
# Method: 
```
Getrandom rng;
rng.get(); //返回unsigned long long范围内的随机数
rng.getint(int left = 0, int right = 100); //获得[left, right) 范围内的随机整数，
                                           //由于long long范围的原因，可能不是均匀分布
                                           //当right - left 比较小时可认为是均匀分布
rng.getdouble(double left = 0.0, double right = 1.0); // 获得[left, right]范围内的随机实数
                                                      //[left, right]范围不能太大
```
