/*
 * FUN_00414580 at 00414580
 * int __register FUN_00414580(int param_1, char * param_2, int param_3)
 * Address ranges: 00414580-004145ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00414580(int param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  int local_c;
  
  local_c = param_3;
  local_c = FUN_0040ed68(*(undefined4 **)(param_1 + 0x18),param_2);
  if (((local_c == 0) && (*(int *)(param_1 + 0x1c) != 0)) &&
     (*(int *)(param_1 + 0x1c) != *(int *)(param_1 + 0x18))) {
    local_c = FUN_0040ed68(*(undefined4 **)(param_1 + 0x1c),param_2);
  }
  if (*(short *)(param_1 + 0x62) != 0) {
    (**(code **)(param_1 + 0x60))(*(undefined4 *)(param_1 + 100),param_1,param_2,&local_c);
  }
  if ((local_c != 0) &&
     (uVar1 = thunk_FUN_004030bc(local_c,(int)&PTR_FUN_0040e948), (char)uVar1 != '\0')) {
    return local_c;
  }
  FUN_0040ec2c(param_2);
  return local_c;
}

