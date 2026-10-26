/*
 * FUN_0045a9f4 at 0045a9f4
 * undefined1 __register FUN_0045a9f4(int param_1, undefined4 param_2)
 * Address ranges: 0045a9f4-0045aa40
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_0045a9f4(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 extraout_ECX;
  undefined1 uVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  uint uVar3;
  
  uVar2 = (undefined1)param_2;
  uVar3 = 0;
  while ((cVar1 = FUN_004581ac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),
                               CONCAT31((int3)((uint)param_2 >> 8),uVar2)), param_2 = extraout_EDX,
         cVar1 == '\0' ||
         (cVar1 = FUN_0045a9e8(param_1,uVar3,CONCAT31((int3)((uint)extraout_ECX >> 8),uVar2)),
         param_2 = extraout_EDX_00, cVar1 != '\0'))) {
    uVar3 = uVar3 + 1;
    if ((char)uVar3 == '\x06') {
      return 1;
    }
  }
  return 0;
}

