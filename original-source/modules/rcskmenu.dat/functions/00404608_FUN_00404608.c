/*
 * FUN_00404608 at 00404608
 * undefined __register FUN_00404608(VARIANT * param_1, VARIANTARG * param_2, char * param_3, int param_4)
 * Address ranges: 00404608-004046f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Type propagation algorithm not settling */

void FUN_00404608(VARIANT *param_1,VARIANTARG *param_2,char *param_3,int param_4)

{
  int *piVar1;
  char cVar2;
  
  cVar2 = *param_3;
  if (cVar2 == '\n') {
    do {
      FUN_00403ba4((int *)param_1,*(undefined4 **)&param_2->n1);
      param_1 = (VARIANT *)((int)&param_1->n1 + 4);
      param_2 = (VARIANTARG *)((int)&param_2->n1 + 4);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  else if (cVar2 == '\v') {
    do {
      FUN_004041bc((BSTR *)param_1,*(OLECHAR **)&param_2->n1);
      param_1 = (VARIANT *)((int)&param_1->n1 + 4);
      param_2 = (VARIANTARG *)((int)&param_2->n1 + 4);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  else if (cVar2 == '\f') {
    do {
      FUN_004048b0(param_1,param_2);
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  else if (cVar2 == '\r') {
    piVar1 = (int *)(param_3 + (byte)param_3[1] + 2);
    do {
      FUN_00404608(param_1,param_2,(char *)piVar1[2],piVar1[1]);
      param_1 = (VARIANT *)((int)&param_1->n1 + *piVar1);
      param_2 = (VARIANTARG *)((int)&param_2->n1 + *piVar1);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  else if (cVar2 == '\x0e') {
    do {
      FUN_004044ec((int)param_1,(int)param_2,(int)param_3);
      param_1 = (VARIANT *)((int)&param_1->n1 + *(int *)(param_3 + (byte)param_3[1] + 2));
      param_2 = (VARIANTARG *)((int)&param_2->n1 + *(int *)(param_3 + (byte)param_3[1] + 2));
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  else if (cVar2 == '\x0f') {
    do {
      FUN_004054a8((int *)param_1,*(int **)&param_2->n1);
      param_1 = (VARIANT *)((int)&param_1->n1 + 4);
      param_2 = (VARIANTARG *)((int)&param_2->n1 + 4);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  else {
    if (cVar2 != '\x11') {
      FUN_004027a0(CONCAT31((int3)((uint)param_1 >> 8),2));
      return;
    }
    do {
      FUN_00404e98((int *)param_1,*(int *)&param_2->n1,(int)param_3);
      param_1 = (VARIANT *)((int)&param_1->n1 + 4);
      param_2 = (VARIANTARG *)((int)&param_2->n1 + 4);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

