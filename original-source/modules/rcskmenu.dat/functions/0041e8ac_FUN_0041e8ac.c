/*
 * FUN_0041e8ac at 0041e8ac
 * undefined4 __register FUN_0041e8ac(uint param_1, uint param_2)
 * Address ranges: 0041e8ac-0041e8e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0041e8ac(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_0047d6d8 != 0) {
    uVar1 = FUN_00417210(param_2);
    iVar2 = FUN_00417210(param_1);
    iVar2 = FUN_0041e680(DAT_0047d6d8,iVar2,uVar1);
    return *(undefined4 *)(iVar2 + 4);
  }
  return 0;
}

