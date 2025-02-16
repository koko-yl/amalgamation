@.str = private unnamed_addr constant [17 x i8] c"Hi from LLVM IR!\00"
declare i32 @puts(i8* nocapture) nounwind
define void @llvm() {
    %cast210 = getelementptr [17 x i8],[17 x i8]* @.str, i64 0, i64 0
    call i32 @puts(i8* %cast210)
    ret void
}
