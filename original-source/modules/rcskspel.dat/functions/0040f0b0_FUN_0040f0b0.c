/*
 * FUN_0040f0b0 at 0040f0b0
 * undefined FUN_0040f0b0(void)
 * Address ranges: 0040f0b0-0040f25a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f0b0(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar3 = param_3;
  if (param_1 < 0xf) {
    puVar3 = *(undefined4 **)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20);
  }
  iVar4 = param_1 * 0x11c;
  switch((&DAT_00503ef4)[param_1 * 0x47]) {
  case 0:
  case 3:
    *param_3 = *(undefined4 *)(&DAT_00503f7c + iVar4);
    *param_4 = *(undefined4 *)(&DAT_00503f80 + iVar4);
    *param_5 = *(undefined4 *)(&DAT_00503f84 + iVar4);
    FUN_0040e070(param_1);
    return;
  default:
    break;
  case 4:
    iVar4 = *(int *)(&DAT_00503ef8 + iVar4) * 0xd0 + DAT_0067ee20;
    iVar4 = FUN_004114c0(*(undefined4 *)(iVar4 + 0x1c),*(undefined4 *)(iVar4 + 0x24));
    iVar2 = FUN_004114c0(puVar3,*(undefined4 *)
                                 ((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x24 + DAT_0067ee20));
    if (iVar2 < iVar4) {
      *param_3 = 0;
      *param_4 = 1;
      *param_5 = 2;
      return;
    }
    if (iVar4 < iVar2) {
      *param_3 = 2;
      *param_4 = 1;
      *param_5 = 0;
      return;
    }
    break;
  case 0x16:
    if ((*(int *)(&DAT_00503f68 + iVar4) < 0) || (cVar1 = FUN_0040eba0(), cVar1 == '\0')) {
      *param_3 = 1;
      *param_4 = 2;
      *param_5 = 0;
      return;
    }
    FUN_0040f290(param_1);
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1b:
    *param_3 = *(undefined4 *)(&DAT_00503f7c + iVar4);
    *param_4 = *(undefined4 *)(&DAT_00503f80 + iVar4);
    *param_5 = *(undefined4 *)(&DAT_00503f84 + iVar4);
    return;
  }
  *param_3 = 1;
  *param_4 = 2;
  *param_5 = 0;
  return;
}

