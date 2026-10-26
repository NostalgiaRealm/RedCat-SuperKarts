/*
 * FUN_0040650f at 0040650f
 * undefined __stdcall FUN_0040650f(void)
 * Address ranges: 0040650f-0040659c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040650f(void)

{
  uint in_EAX;
  uint uVar1;
  uint extraout_ECX;
  
  if (in_EAX != 0) {
    (*(code *)PTR_FUN_0040ef60)();
    uVar1 = DAT_0040e864;
    if (((DAT_004104c8 == 0) || (in_EAX < DAT_004104c8)) || (*(uint *)(DAT_004104c8 + 8) <= in_EAX))
    {
      for (; (*(uint *)(uVar1 + 8) != 0 && ((in_EAX < uVar1 || (*(uint *)(uVar1 + 8) <= in_EAX))));
          uVar1 = *(uint *)(uVar1 + 8)) {
      }
    }
    FUN_00407ac6();
    if ((extraout_ECX < DAT_0040e868) && (DAT_0040e86c < *(uint *)(extraout_ECX + 0x14))) {
      DAT_0040e86c = *(uint *)(extraout_ECX + 0x14);
    }
    DAT_004104e8 = 0;
    DAT_004104c8 = extraout_ECX;
    (*(code *)PTR_FUN_0040ef68)();
  }
  return;
}

