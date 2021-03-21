class Person {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }

    greeting() {
        console.log(`Kneel befor ${this.name} the great.`);
    }
}

module.exports = Person;