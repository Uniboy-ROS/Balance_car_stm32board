 (board_balance_car) STM32_breathing_LED
===================================
## 模式介紹

    如下圖所示
    板子內建LED接腳為"PA4"
    Programming Mode Boot 下0上1 (BOOT0接1，BOOT1接0)
    Operating   Mode Boot 上下皆0 (BOOT0和BOOT1接0)
    BOOT0在圖上方，BOOT1在圖下方
    
![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/Jumper_contrast.jpg)

## Micro USB(serial)

* 請切換到Programming Mode Boot 下0上1
* 因為此板有整合CH340G(USB轉串口)的芯片，所以這個接口只能用serial燒錄
* 記得在工具/開發板 將Upload method 設為Serial
    
        照範例" Blink "跑，應該會如圖所示
    
![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/Micro_USB.jpg)
    
        回傳值應該如下

![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/serial_output.PNG)

## ST-LINK

* Programming Mode Boot 下0上1 按下Reset 會clear 斷電等同
* Operating Mode Boot 下0上0 按下Reset 會loop 所以斷電後在接上一樣會繼續執行

        記得在工具/開發板 將Upload method 設為STLink
        但因為讀不到序列埠，所以看不到回傳值始屬正常

        從ST-LINK 拉出SWDIO.GND.SWCLK.3.3V 4條線接到 板子對應的腳位上(A13-SWDIO、A14-SWCLK)
        便可以跑範例程式Blink了

![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/ST-LINK1.jpg)






 無BOOT板
===========

* 如果當有電路板沒有BOOT，全部都接去GND時，該怎麼燒錄呢?
    
        如下圖所示:
![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/NO_BOOT.jpg)

        1.那麼首先請你將Micro USB插上
        2.接著開啟Arduino IDE的序列埠監控視窗
        3.然後呢，呼吸燈程式可採用stm32car_blink
        4.最後，按下板子上的RESET鍵就可以燒錄了喔

* 板子內建LED接腳為"PB13"
* 備註:在未開啟序列埠監控視窗時，按下RESET它也只會RUN程式而已
* 但是在開啟序列埠監控視窗時，按下RESET他便會中止，所以才能燒錄。



# STM32互相傳訊

* Serial = Serial1 => Usart1 Tx = PA9  , Rx = PA10
*          Serial2 => Usart2 Tx = PA2  , Rx = PA3
*          Serial3 => Usart3 Tx = PB10 , Rx = PB11


        檢測方式如下:
        1.首先我們先了解如何傳訊，"USB1 --> FTDI -->' bluepill '<-> Serial2 <->' noboot '<-- USB2"
        2.因為一開始程式燒進去時都會跑預設的Serial，所以我們會使用Serial2來為兩個板子作傳訊
        3.接腳: 
                        GND -> G   
                        5V  -> 5V                G   ->  G
                FTDI    TXD -> PA10   bluepill   PA2 ->  PA3    noboot
                        RXD -> PA9               PA3 ->  PA2


![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/communication.jpg)


        4.上述沒問題後，請使用stm32_communication裡面的程式，因應板子型號將各自程式燒進去
        5.最後成果應該會如下

![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/port8.PNG)
![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/port10.PNG)


        希望以上能對各位小伙伴有幫助。
    
![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/greenflash.jpg)
