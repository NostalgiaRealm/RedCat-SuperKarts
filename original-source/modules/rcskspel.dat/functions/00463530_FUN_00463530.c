/*
 * FUN_00463530 at 00463530
 * undefined FUN_00463530(void)
 * Address ranges: 00463530-004635bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00463530(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_004d292c;
  iVar2 = param_1[0x28];
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  iVar2 = param_1[0x22];
  param_1[0x21] = &PTR_FUN_004d291c;
  if (iVar2 != 0) {
    FUN_004bc150(*(undefined4 *)(iVar2 + 4));
    *(undefined4 *)(iVar2 + 4) = 0;
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    FUN_004bc150(iVar2);
  }
  param_1[0x22] = 0;
  FUN_00458670();
  return;
}

