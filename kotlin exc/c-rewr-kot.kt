import java.util.Scanner

class Medicine(
    var name: String, 
    var exp_date: String, 
    var id: Long, 
    var price: Float, 
    var quant: Int
)

fun check_date(meds:Array<Medicine>, date:String):Array<Medicine>{
    var req_scanner = Scanner(date)
    var rmonth = req_scanner.nextInt()
    req_scanner.next()
    var ryear = req_scanner.nextInt()
    req_scanner.close()
    var emptyMedArray = emptyArray<Medicine>()
    var listed_meds = emptyMedArray.toMutableList()
    var found = 0
    for(obj in meds){
        var obj_scanner = Scanner(obj.exp_date)
        var month = obj_scanner.nextInt()
        obj_scanner.next()
        var year = obj_scanner.nextInt()
        obj_scanner.close()
        if(rmonth>month && ryear == year || ryear>year){
            found = 1
            listed_meds.add(obj)
        }
    }
    if(found == 1){
        return listed_meds
    } else{
        return NULL
    }
}

fun delete_entry(meds:MutableList<Medicine>, mname:String, date:String){
    var found = 0
    var d_obj:Medicine
    for(obj in meds){
        if(obj.name == mname && obj.date == date){
            found = 1
            d_obj = obj
            break
        }
    }
    if(found==0){
        println("Not found")
    }
    meds.remove(d_obj)
}

fun main(){
    var med1 = Medicine("Ibuprofen", "12.03.2029", 124234234, 23.4, 4)
}