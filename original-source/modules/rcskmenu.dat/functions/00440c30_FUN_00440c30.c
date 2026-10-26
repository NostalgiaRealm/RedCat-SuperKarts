/*
 * FUN_00440c30 at 00440c30
 * undefined __register FUN_00440c30(int * param_1, int param_2)
 * Address ranges: 00440c30-00440c68
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440c30(int *param_1,int param_2)

{
  byte bVar1;
  undefined3 extraout_var;
  
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  if ((*(byte *)((int)param_1 + 0x41) & 0x10) == 0) {
    bVar1 = FUN_00429770(CONCAT22(*(short *)(param_2 + 10) >> 0xf,*(undefined2 *)(param_2 + 4)));
    FUN_00403088(param_1,CONCAT31(extraout_var,bVar1),(int)*(short *)(param_2 + 8));
  }
  return;
}

