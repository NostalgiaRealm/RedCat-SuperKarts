/*
 * FUN_0048dc30 at 0048dc30
 * undefined FUN_0048dc30(void)
 * Address ranges: 0048dc30-0048dcde
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048dc30(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int iVar3;
  int in_stack_000011b4;
  
  FUN_004c0200();
  bVar1 = false;
  iVar2 = (**(code **)*extraout_ECX)();
  if (iVar2 < 10) {
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        if (*(int *)(iVar3 * 0x11b0 + 0x1180 + *(int *)(extraout_ECX[1] + 4)) == in_stack_000011b4)
        {
          bVar1 = true;
          iVar3 = iVar2;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
      if (bVar1) {
        return;
      }
    }
    FUN_0048c510();
    FUN_0048de90(*(undefined4 *)(extraout_ECX[1] + 4),1,&stack0x00000000);
    FUN_0048c9a0(in_stack_000011b4,0);
    (&DAT_00504000)[*(int *)(in_stack_000011b4 * 0xd0 + 0x10 + DAT_0067ee20) * 0x11c] = 1;
  }
  return;
}

