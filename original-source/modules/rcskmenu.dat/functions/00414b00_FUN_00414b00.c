/*
 * FUN_00414b00 at 00414b00
 * undefined __register FUN_00414b00(int param_1, int * param_2)
 * Address ranges: 00414b00-00414b68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414b00(int param_1,int *param_2)

{
  undefined4 local_8;
  
  local_8 = 0;
  if (param_2[8] != 0) {
    local_8 = *(undefined4 *)(param_2[8] + 0x18);
  }
  (**(code **)(*param_2 + 4))
            (param_2,&DAT_00414b74,*(short *)(param_1 + 0x18) != (short)local_8,&LAB_004148d4,
             param_1,&LAB_004148ac,param_1);
  (**(code **)(*param_2 + 4))
            (param_2,&DAT_00414b84,local_8._2_2_ != *(short *)(param_1 + 0x1a),&LAB_004148e0,param_1
             ,FUN_004148c0,param_1);
  return;
}

