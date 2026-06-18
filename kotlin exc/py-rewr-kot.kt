class FoodDelivery(
    var order_number:Int,
    var destination:String,
    var price:Float,
    var delivery_term:String,
    var order_status:String){
        fun order_info(){
            println(this.order_number)
            println(this.destination)
            println(this.price)
            println(this.delivery_term)
            println(this.order_status)
        }
        fun change_term(){
            this.delivery_term = readln()
        }
    }

fun status_info(arr:Array<FoodDelivery>,num:Int){
    var found = 0
    for(obj in arr){
        if(arr.order_number == num){
            println("Found")
            found = 1
            break
        }
    }
    if(found = 0){
        println("Not found")
    }
}

fun add_order(arr:Array<FoodDelivery>,obj:FoodDelivery):Array<FoodDelivery>{
    var new_arr = arr + obj
    return new_arr
}

fun main(){
    var nums = mutableListOf<Int>()
    for(i in 0..19){
        nums.add(readln().toInt())
    }
    var sum = nums.maxOrNull() + nums.minOrNull()
    var odd = 0
    for(num in nums){
        if(num%2!=0){
            ++odd
        }
    }
    var nums2 = mutableListOf<Int>()
    for(num in nums){
        if(num%5==0){
            nums2.add(num)
        }
    }
    var sum2, avg
    for(num in nums2){
        sum2+=num
    }
    avg = sum2/num2.size
    println(avg+nums2.maxOrNull())
    num2.add(num2[0]+num2[num2.size-1])
}