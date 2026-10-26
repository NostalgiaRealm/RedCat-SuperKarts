/*
 * FUN_00409d69 at 00409d69
 * int * __cdecl FUN_00409d69(LPCSTR param_1)
 * Address ranges: 00409d69-00409f1f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __cdecl FUN_00409d69(LPCSTR param_1)

{
  int *piVar1;
  int iVar2;
  int local_8;
  
  if ((DAT_0043d468 == 0) || (DAT_0043d46c == 1)) {
    piVar1 = (int *)FUN_0041f4c6(param_1,&DAT_0043122c);
    if (piVar1 == (int *)0x0) {
      FUN_004015a6((byte *)s__s__d____file_open_failed___s__0043123c);
      piVar1 = (int *)0x0;
    }
    else {
      FUN_004015a6((byte *)s__s__d____file_open_succeeded___s_0043126c);
    }
  }
  else {
    for (local_8 = 0; local_8 < DAT_0043d45c; local_8 = local_8 + 1) {
      iVar2 = __strcmpi((char *)(DAT_0043d460 + local_8 * 0x1c),param_1);
      if (iVar2 == 0) {
        DAT_0043d464 = *(int *)(DAT_0043d460 + 0x14 + local_8 * 0x1c);
        DAT_0043d450 = DAT_0043d464 + *(int *)(DAT_0043d460 + 0x18 + local_8 * 0x1c);
        break;
      }
    }
    if (local_8 == (short)DAT_0043d45c) {
      piVar1 = (int *)FUN_0041f4c6(param_1,&DAT_00431294);
      if (piVar1 == (int *)0x0) {
        FUN_004015a6((byte *)s__s__d____file_open_failed___s__004312a4);
        piVar1 = (int *)0x0;
      }
      else {
        FUN_004015a6((byte *)s__s__d____file_open_succeeded___s_004312d4);
      }
    }
    else {
      FUN_0041fd07(DAT_0043d458,DAT_0043d464,0);
      FUN_00427d94((int)DAT_0043d458);
      FUN_004015a6((byte *)s__s__d____file_open_succeeded___s_00431308);
      piVar1 = DAT_0043d458;
    }
  }
  return piVar1;
}

