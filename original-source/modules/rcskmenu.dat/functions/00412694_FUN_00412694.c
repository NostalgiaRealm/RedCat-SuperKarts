/*
 * FUN_00412694 at 00412694
 * int __register FUN_00412694(int param_1, int * param_2, undefined4 * param_3)
 * Address ranges: 00412694-004126f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00412694(int param_1,int *param_2,undefined4 *param_3)

{
  int local_114;
  char local_110 [4];
  byte local_10c [256];
  
  FUN_00403dac(local_10c,param_3,0xff);
  local_114 = FUN_0040310c(*param_2,local_10c);
  local_110[0] = local_114 == 0;
  if (*(short *)(param_1 + 0x3a) != 0) {
    (**(code **)(param_1 + 0x38))
              (*(undefined4 *)(param_1 + 0x3c),param_1,param_3,local_110,&local_114);
  }
  if (local_110[0] != '\0') {
    FUN_004124c0();
  }
  return local_114;
}

