/*
 * FUN_00419874 at 00419874
 * undefined4 __cdecl FUN_00419874(int param_1, char param_2)
 * Address ranges: 00419874-00419d5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00419874(int param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  size_t sVar5;
  uint local_c;
  
  iVar1 = FUN_00412a9d(param_1);
  piVar2 = (int *)FUN_00412b01(param_1);
  iVar3 = FUN_00412d96();
  FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
  switch(param_2) {
  case '\b':
    if (piVar2[0xb] != 0) {
      sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
      if ((uint)piVar2[0xb] < sVar5) {
        for (local_c = piVar2[0xb];
            sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50)), local_c < sVar5 + 1;
            local_c = local_c + 1) {
          *(undefined1 *)((int)piVar2 + local_c + piVar2[0xc] * 0x65 + 0x4f) =
               *(undefined1 *)((int)piVar2 + local_c + piVar2[0xc] * 0x65 + 0x50);
        }
        piVar2[0xb] = piVar2[0xb] + -1;
        FUN_004195c9(piVar2,(int *)(iVar3 + iVar1 * 0x1c));
      }
      else {
        piVar2[0xb] = piVar2[0xb] + -1;
        *(undefined1 *)((int)piVar2 + piVar2[0xb] + piVar2[0xc] * 0x65 + 0x50) = 0;
        FUN_004195c9(piVar2,(int *)(iVar3 + iVar1 * 0x1c));
      }
    }
    break;
  default:
    puVar4 = FUN_0041fb70((uint *)&DAT_0043de00,&param_2);
    if (puVar4 == (uint *)0x0) {
      return 0;
    }
    sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
    if ((piVar2[0xb] < *piVar2) && ((int)sVar5 < *piVar2)) {
      if (piVar2[0xd] == 0) {
        FUN_00419758(piVar2,(int *)(iVar3 + iVar1 * 0x1c),param_2);
      }
      else {
        FUN_00419654(piVar2,(int *)(iVar3 + iVar1 * 0x1c),param_2);
      }
    }
    break;
  case '\r':
  case '(':
    if (piVar2[0xc] < piVar2[1] + -1) {
      piVar2[0xc] = piVar2[0xc] + 1;
      sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
      if (sVar5 < (uint)piVar2[0xb]) {
        sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
        piVar2[0xb] = sVar5;
      }
      FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    }
    break;
  case '\x1b':
    piVar2[0xb] = 0;
    *(undefined1 *)((int)piVar2 + piVar2[0xb] + piVar2[0xc] * 0x65 + 0x50) = 0;
    FUN_004195c9(piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    break;
  case '#':
    sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
    piVar2[0xb] = sVar5;
    FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    break;
  case '$':
    piVar2[0xb] = 0;
    FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    break;
  case '%':
    if (0 < piVar2[0xb]) {
      piVar2[0xb] = piVar2[0xb] + -1;
      FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    }
    break;
  case '&':
    if (0 < piVar2[0xc]) {
      piVar2[0xc] = piVar2[0xc] + -1;
      sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
      if (sVar5 < (uint)piVar2[0xb]) {
        sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
        piVar2[0xb] = sVar5;
      }
      FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    }
    break;
  case '\'':
    sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
    if ((uint)piVar2[0xb] < sVar5) {
      piVar2[0xb] = piVar2[0xb] + 1;
      FUN_00419275((int)piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    }
    break;
  case '-':
    if (piVar2[0xd] == 0) {
      piVar2[0xd] = 1;
    }
    else {
      piVar2[0xd] = 0;
    }
    break;
  case '.':
    sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50));
    if (piVar2[0xb] != sVar5) {
      for (local_c = piVar2[0xb]; sVar5 = _strlen((char *)((int)piVar2 + piVar2[0xc] * 0x65 + 0x50))
          , local_c < sVar5; local_c = local_c + 1) {
        *(undefined1 *)((int)piVar2 + local_c + piVar2[0xc] * 0x65 + 0x50) =
             *(undefined1 *)((int)piVar2 + local_c + piVar2[0xc] * 0x65 + 0x51);
      }
      FUN_004195c9(piVar2,(int *)(iVar3 + iVar1 * 0x1c));
    }
  }
  return 1;
}

