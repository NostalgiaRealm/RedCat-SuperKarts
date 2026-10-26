/*
 * FUN_004be16b at 004be16b
 * undefined FUN_004be16b(void)
 * Address ranges: 004be16b-004be1ac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004be16b(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_004be0dc(0);
  puVar2 = *(undefined4 **)(param_1 + 0x18);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    FUN_004bc150(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    FUN_004bc150(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}

