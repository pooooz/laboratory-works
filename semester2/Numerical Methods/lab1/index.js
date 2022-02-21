function functionValue(x) {
  return 3 * x - Math.cos(x) - 1;
}

function functionFiValue(x) {
  return (Math.cos(x) + 1) / 3;
}

function secondFunctionValue(x) {
  return x * x * x - 5 * x - 1;
}

function secondFunctionFiValue1(x) {
  return (x * x * x - 1) / 5;
}

function secondFunctionFiValue2(x) {
  return Math.cbrt((1 + 5 * x));
}

function dichotomyMethod(a, b, eps) {
  let start = a;
  let end = b;
  let xi = (start + end) / 2;
  for (let i = 0; xi > eps; i++) {
    if ((end - start) / 2 <= eps || functionValue(xi) === 0) {
      console.log(`Количество итераций по методу дихотомии: ${i}`);
      return xi;
    } else if (functionValue(xi) > 0) {
      end = xi;
      xi = (start + end) / 2;
    } else {
      start = xi;
      xi = (start + end) / 2;
    }
  }
}3

function simpleIterationMethod(a, eps, functionName) {
  let approximation = a;
  let xi = functionName(approximation);

  let i = 1;
  while (true) {
    xi = functionName(approximation);
    i++;
    if (Math.abs(xi - approximation) < eps) {
      break;
    }
    approximation = xi;
  }

  console.log(`Количество итераций по методу простой итерации: ${i}`);

  return xi;
}

function secantMethod(a, eps) {
  let approximation = a;
  let xi = approximation - ((functionValue(approximation) * (approximation - 0.5)) / (functionValue(approximation) - functionValue(0.5)));
  let i = 0;
  while (Math.abs(xi - approximation) > eps) {
    approximation = xi;
    xi = approximation - ((functionValue(approximation) * (approximation - 0.5)) / (functionValue(approximation) - functionValue(0.5)));
    i++;
  }

  console.log(`Количество итераций по методу секущих: ${i}`);

  return xi;
}

function chordMethod(a, eps) {
  let approximation = a;
  let xi = approximation - ((functionValue(approximation) * (0.8 - approximation)) / (functionValue(0.8) - functionValue(approximation)));
  let i = 0;
  while (Math.abs(xi - approximation) > eps) {
    approximation = xi;
    xi = approximation - ((functionValue(approximation) * (approximation - 0.5)) / (functionValue(approximation) - functionValue(0.5)));
    i++;
  }

  console.log(`Количество итераций по методу хорд: ${i}`);

  return xi;
}

function task1() {
  console.log("Задание 1!");

  const inputValue = Number(document.querySelector(".task1__input").value);
  if (inputValue !== 0) {
    let a, b;
    for (let i = 0.4; i < 0.8; i += inputValue) {
      if (functionValue(i) * functionValue(i + inputValue) < 0) {
        console.log(`Корень находится в промежутке от ${i.toFixed(4)} до ${(i + inputValue).toFixed(4)}`);
        a = i;
        b = i + inputValue;
      }
    }

    console.log("------");

    let dichotomyRoot = dichotomyMethod(a, b, 0.001);
    console.log(`Корень уравения по методу дихотомии: ${dichotomyRoot}`);

    console.log("------");

    let simpleIterationMethodRoot = simpleIterationMethod(a, 0.001, functionFiValue);
    console.log(`Корень уравения по методу простой итерации: ${simpleIterationMethodRoot}`);

    console.log("------");

    // Первое начальное приближение, то есть 0.4 подобрано аналитически
    let secantMethodRoot = secantMethod(0.4, 0.001);
    console.log(`Корень уравения по методу секущих: ${secantMethodRoot}`);

    console.log("------");

    let chordMethodRoot = chordMethod(0.4, 0.001);
    console.log(`Корень уравения по методу хорд: ${chordMethodRoot}`);

  } else {
      console.error("Некорректный ввод для задания 1");
  }
}

function task2() {
  console.log("Задание 2!");

  const inputValue = Number(document.querySelector(".task2__input").value);
  if (inputValue !== 0) {
    const gaps = {};
    let a, b;
    let objectIterator = 0;
    for (let i = -3; i < 3; i += inputValue) {
      if (secondFunctionValue(i) * secondFunctionValue(i + inputValue) < 0) {
        console.log(`Корень находится в промежутке от ${i.toFixed(4)} до ${(i + inputValue).toFixed(4)}`);
        a = i;
        b = i + inputValue;
        gaps["gap" + objectIterator] = [a, b];
        objectIterator++;
      }
    }

    for (gap in gaps) {
      if (gap === "gap0" || gap === "gap2") {
        console.log(simpleIterationMethod(gaps[gap][0], 0.001, secondFunctionFiValue2));
      } else {
        console.log(simpleIterationMethod(gaps[gap][0], 0.001, secondFunctionFiValue1));
      }
    }

  } else {
    console.error("Некорректный ввод для задания 2");
  }
}

document.querySelector(".task1__button").addEventListener("click", () => {
  task1();
});

document.querySelector(".task2__button").addEventListener("click", () => {
  task2();
});