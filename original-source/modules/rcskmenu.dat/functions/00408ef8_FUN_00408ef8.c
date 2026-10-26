/*
 * FUN_00408ef8 at 00408ef8
 * undefined __register FUN_00408ef8(short * param_1, ushort * param_2, short * param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 00408ef8-00408f15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408ef8(short *param_1,ushort *param_2,short *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uStack_8;
  
  uStack_8 = param_3;
  FUN_00408db4(param_1,param_2,param_3,(undefined2 *)((int)&uStack_8 + 2),param_4,param_5);
  return;
}

