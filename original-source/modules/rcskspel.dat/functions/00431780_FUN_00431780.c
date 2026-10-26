/*
 * FUN_00431780 at 00431780
 * undefined FUN_00431780(void)
 * Address ranges: 00431780-00431818
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00431780(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0x500;
  DirectInputCreateA(param_2,0x500,param_1,0);
  puVar1 = param_1 + 1;
  (**(code **)(*(int *)*param_1 + 0xc))((int *)*param_1,&DAT_004d3010,puVar1,0);
  (**(code **)(*(int *)*puVar1 + 0x2c))((int *)*puVar1,&DAT_0048f100);
  (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1,uVar2,5);
  (**(code **)(*(int *)*puVar1 + 0x1c))((int *)*puVar1);
  param_1[0xc] = 0x2c;
  (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,param_1 + 0xc);
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}

