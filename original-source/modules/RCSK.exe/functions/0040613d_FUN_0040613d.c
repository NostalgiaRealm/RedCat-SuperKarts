/*
 * FUN_0040613d at 0040613d
 * undefined4 __cdecl FUN_0040613d(undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4)
 * Address ranges: 0040613d-00406340
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_0040613d(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  size_t sVar1;
  void *pvVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 uVar5;
  char cVar6;
  undefined4 *puVar7;
  size_t sVar8;
  uint *puVar9;
  undefined4 *puVar10;
  
  sVar8 = 2;
  sVar3 = sVar8;
  for (puVar7 = param_1; (char *)*puVar7 != (char *)0x0; puVar7 = puVar7 + 1) {
    sVar1 = _strlen((char *)*puVar7);
    sVar3 = sVar3 + 1 + sVar1;
  }
  pvVar2 = _malloc(sVar3);
  *param_3 = pvVar2;
  if (pvVar2 == (void *)0x0) {
    *param_4 = 0;
LAB_0040625e:
    DAT_00408c04 = 0xc;
    DAT_00408c08 = 8;
LAB_00406272:
    uVar5 = 0xffffffff;
  }
  else {
    puVar7 = param_2;
    if (param_2 == (undefined4 *)0x0) {
      *param_4 = 0;
      puVar7 = param_4;
      puVar10 = param_4;
    }
    else {
      for (; (char *)*puVar7 != (char *)0x0; puVar7 = puVar7 + 1) {
        sVar3 = _strlen((char *)*puVar7);
        sVar8 = sVar8 + 1 + sVar3;
      }
      if (DAT_00408c50 == (char *)0x0) {
        DAT_00408c50 = FUN_00404082();
        if (DAT_00408c50 != (LPSTR)0x0) goto LAB_004061db;
        goto LAB_00406272;
      }
LAB_004061db:
      puVar7 = (undefined4 *)0x0;
      if (*DAT_00408c50 != '\0') {
        cVar6 = *DAT_00408c50;
        pcVar4 = DAT_00408c50;
        do {
          if (cVar6 == '=') break;
          sVar3 = _strlen(pcVar4);
          puVar7 = (undefined4 *)((int)puVar7 + sVar3 + 1);
          cVar6 = DAT_00408c50[(int)puVar7];
          pcVar4 = DAT_00408c50 + (int)puVar7;
        } while (cVar6 != '\0');
      }
      pcVar4 = DAT_00408c50 + (int)puVar7;
      puVar10 = puVar7;
      while ((((*pcVar4 == '=' && (pcVar4[1] != '\0')) && (pcVar4[2] == ':')) && (pcVar4[3] == '='))
            ) {
        sVar3 = _strlen(pcVar4 + 4);
        puVar10 = (undefined4 *)((int)puVar10 + sVar3 + 5);
        pcVar4 = DAT_00408c50 + (int)puVar10;
      }
      pvVar2 = _malloc((int)puVar10 + (sVar8 - (int)puVar7));
      *param_4 = pvVar2;
      if (pvVar2 == (void *)0x0) {
        FUN_00401779((LPVOID)*param_3);
        *param_3 = 0;
        goto LAB_0040625e;
      }
    }
    puVar9 = (uint *)*param_3;
    param_3 = param_1;
    if ((uint *)*param_1 != (uint *)0x0) {
      FUN_00405450(puVar9,(uint *)*param_1);
      param_3 = param_1 + 1;
      sVar3 = _strlen((char *)*param_1);
      puVar9 = (uint *)((int)puVar9 + sVar3 + 1);
      goto LAB_00406299;
    }
    while( true ) {
      puVar9 = (uint *)((int)puVar9 + 1);
LAB_00406299:
      if ((uint *)*param_3 == (uint *)0x0) break;
      FUN_00405450(puVar9,(uint *)*param_3);
      sVar3 = _strlen((char *)*param_3);
      puVar9 = (uint *)((int)puVar9 + sVar3);
      *(undefined1 *)puVar9 = 0x20;
      param_3 = param_3 + 1;
    }
    *(undefined1 *)((int)puVar9 + -1) = 0;
    *(undefined1 *)puVar9 = 0;
    puVar9 = (uint *)*param_4;
    if (param_2 != (undefined4 *)0x0) {
      FUN_00402450(puVar9,(undefined4 *)(DAT_00408c50 + (int)puVar7),(int)puVar10 - (int)puVar7);
      puVar9 = (uint *)((int)puVar9 + ((int)puVar10 - (int)puVar7));
      for (; (uint *)*param_2 != (uint *)0x0; param_2 = param_2 + 1) {
        FUN_00405450(puVar9,(uint *)*param_2);
        sVar3 = _strlen((char *)*param_2);
        puVar9 = (uint *)((int)puVar9 + sVar3 + 1);
      }
    }
    if (puVar9 != (uint *)0x0) {
      if (puVar9 == (uint *)*param_4) {
        *(undefined1 *)puVar9 = 0;
        puVar9 = (uint *)((int)puVar9 + 1);
      }
      *(undefined1 *)puVar9 = 0;
    }
    FUN_00401779(DAT_00408c50);
    DAT_00408c50 = (char *)0x0;
    uVar5 = 0;
  }
  return uVar5;
}

