 (board_balance_car) STM32_breathing_LED
===================================
## 模式介紹

    如下圖所示
    板子內建 LED 接腳為" PA4 "
    Programming Mode Boot 下 0 上 1 ( BOOT0 接 1 ， BOOT1 接 0 )
    Operating   Mode Boot 上下皆 0 ( BOOT0 和 BOOT1 接 0 )
    BOOT0 在圖上方，BOOT1 在圖下方
    
![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/Jumper_contrast.jpg)

## Micro USB(serial)

* 請切換到 Programming Mode Boot 下 0 上 1
* 因為此板有整合 CH340G ( USB 轉串口)的芯片，所以這個接口只能用 serial 燒錄，要再次燒錄前記得按下 RESET。
* 記得在工具/開發板 將 Upload method 設為 Serial
    
        照範例" Blink "跑，應該會如圖所示
    
![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/Micro_USB.jpg)
    
        回傳值應該如下

![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/serial_output.PNG)

## ST-LINK
* 這在兩個模式下都可執行。
* Programming Mode Boot 下 0 上 1 按下 Reset 會 clear 斷電等同
* Operating Mode Boot 下 0 上 0 按下 Reset 會 loop 所以斷電後在接上一樣會繼續執行
* 記得在工具/開發板 將 Upload method 設為 STLink
        

        但因為讀不到序列埠，所以看不到回傳值始屬正常
        從 ST-LINK 拉出 SWDIO . GND . SWCLK . 3.3V 4條線接到 板子對應的腳位上( A13-SWDIO 、 A14-SWCLK )
        便可以跑範例程式 Blink 了

![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/ST-LINK1.jpg)






 無BOOT板
===========

* 如果當有電路板沒有 BOOT ，全部都接去 GND 時，該怎麼燒錄呢?
* 記得在工具/開發板 將 Upload method 設為 Serial 

        如下圖所示:
![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/NO_BOOT.jpg)



        1.那麼首先請你將 Micro USB 插上
        2.接著開啟 Arduino IDE 的序列埠監控視窗
        3.然後呢，呼吸燈程式可採用 stm32car_blink
        4.最後，按下板子上的 RESET 鍵就可以燒錄了喔

* 板子內建 LED 接腳為" PB13 "
* 備註:在未開啟序列埠監控視窗時，按下 RESET 它也只會 Return 程式而已
* 但是在開啟序列埠監控視窗時，按下 RESET 他便會中止，所以才能燒錄。



# STM32互相傳訊

* Serial1 => Usart1 Tx = PA9  , Rx = PA10
* Serial2 => Usart2 Tx = PA2  , Rx = PA3
* Serial3 => Usart3 Tx = PB10 , Rx = PB11


        檢測方式如下:
        1.首先我們先了解如何傳訊，"USB1 --> FTDI -->' bluepill '<-> Serial2 <->' noboot '<-- USB2"
        2.因為一開始程式燒進去時都會跑預設的 Serial ，所以我們會使用 Serial2 來為兩個板子作傳訊
        3.接腳: 
                        GND -> G   
                        5V  -> 5V                G   ->  G
                FTDI    TXD -> PA10   bluepill   PA2 ->  PA3    noboot
                        RXD -> PA9               PA3 ->  PA2


![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/communication.jpg)


        4.上述沒問題後，請使用 stm32_communication 裡面的程式，因應板子型號將各自程式燒進去
        5.最後成果應該會如下

![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/port8.PNG)
![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/port10.PNG)


        希望以上能對各位小伙伴有幫助。
    
![image](https://github.com/Uniboy-ROS/Balance_car_stm32board/blob/master/image/greenflash.jpg)
