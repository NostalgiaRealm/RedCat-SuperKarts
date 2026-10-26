/*
 * FUN_0044b360 at 0044b360
 * undefined __register FUN_0044b360(int * param_1, undefined4 param_2, undefined1 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined1 param_7)
 * Address ranges: 0044b360-0044b3c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b360(int *param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined1 param_7)

{
  undefined4 uVar1;
  undefined3 in_register_00000005;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  
  if ((*(byte *)((int)param_1 + 0x13a) & (byte)param_6) != 0) {
    uVar1 = FUN_0044b2c8(param_1);
    if ((char)uVar1 == '\0') {
      (**(code **)(*param_1 + 0x84))();
      in_register_00000005 = extraout_var_00;
    }
    else {
      (**(code **)(*param_1 + 0x80))();
      in_register_00000005 = extraout_var;
    }
  }
  if (*(short *)((int)param_1 + 0x132) != 0) {
    (*(code *)param_1[0x4c])
              (param_1[0x4d],param_2,CONCAT31(in_register_00000005,param_3),param_4,param_5,param_6,
               param_7);
  }
  return;
}

