/*
 * FUN_004409c0 at 004409c0
 * undefined __register FUN_004409c0(int * param_1, int param_2, undefined1 param_3, byte param_4)
 * Address ranges: 004409c0-00440a01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004409c0(int *param_1,int param_2,undefined1 param_3,byte param_4)

{
  byte bVar1;
  undefined3 extraout_var;
  undefined4 extraout_EDX;
  
  if ((*(byte *)((int)param_1 + 0x41) & 0x10) == 0) {
    bVar1 = FUN_00429770(CONCAT22(*(short *)(param_2 + 10) >> 0xf,*(undefined2 *)(param_2 + 4)));
    FUN_00403088(param_1,CONCAT31((int3)((uint)extraout_EDX >> 8),param_3),
                 CONCAT31(extraout_var,bVar1 | param_4));
  }
  return;
}

