/*
 * FUN_0040ad5c at 0040ad5c
 * undefined __register FUN_0040ad5c(int param_1, char param_2, undefined4 * param_3, undefined4 param_4, undefined4 param_5)
 * Address ranges: 0040ad5c-0040adc7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ad5c(int param_1,char param_2,undefined4 *param_3,undefined4 param_4,undefined4 param_5
                 )

{
  undefined4 *extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 **ppuVar1;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 in_stack_ffffffd8;
  undefined4 in_stack_ffffffdc;
  byte *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  local_c = (byte *)0x0;
  if (param_2 != '\0') {
    puStack_2c = (undefined1 *)0x40ad72;
    param_1 = FUN_004031ac(param_1,param_2,param_3,in_stack_ffffffd8,in_stack_ffffffdc);
    param_3 = extraout_ECX;
  }
  puStack_30 = &LAB_0040adc8;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  ppuVar1 = &local_8;
  puStack_2c = &stack0xfffffffc;
  FUN_00405438(param_3,(int *)&local_c);
  FUN_00408a5c(local_c,param_5,param_4,(int *)ppuVar1);
  FUN_00403ba4((int *)(param_1 + 4),local_8);
  *in_FS_OFFSET = uStack_34;
  puStack_2c = &LAB_0040adcf;
  puStack_30 = (undefined1 *)0x40adc7;
  FUN_00403b74((int *)&local_c,2);
  return;
}

