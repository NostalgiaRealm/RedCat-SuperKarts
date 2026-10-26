/*
 * FUN_00408c54 at 00408c54
 * undefined __register FUN_00408c54(undefined2 * param_1, undefined2 * param_2, undefined2 * param_3, undefined2 * param_4, undefined4 param_5, undefined4 param_6)
 * Address ranges: 00408c54-00408caf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408c54(undefined2 *param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  ushort *puVar1;
  uint local_10 [2];
  ushort local_8;
  ushort local_6;
  
  puVar1 = &local_8;
  FUN_00408ba4(local_10,param_2,param_3,(double)CONCAT44(param_6,param_5));
  FUN_00407ba8(local_10[0],CONCAT22(extraout_var,60000),&local_6,puVar1);
  FUN_00407ba8((uint)local_6,CONCAT22(extraout_var_00,0x3c),param_1,param_2);
  FUN_00407ba8((uint)local_8,CONCAT22(extraout_var_01,1000),param_3,param_4);
  return;
}

